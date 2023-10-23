#include<Windows.h>
#include<iostream>
using namespace std;

int main()
{

    //Local variables Declaration
    char *buffer = NULL;
    char message[1024] = "I am good, How are you ?";

    //1. Create File Mapping
    HANDLE hFileMap = CreateFileMapping(
    INVALID_HANDLE_VALUE,
    NULL,
    PAGE_READWRITE,
    0,
    256,
    L"myfile"
    );

    if(hFileMap == NULL)
    {
        cout<<"CreateFileMapping failed :Error: "<<GetLastError()<<endl;
        return 0;
    }
     cout<<"CreateFileMapping Succeeded "<<endl;

    //2. Create File View for the process

    buffer = (char*)MapViewOfFile(
        hFileMap,
        FILE_MAP_ALL_ACCESS,
        0,
        0,
        256 // The no of bytes of the Mapping object to access 
    );  
   
    if(buffer == NULL)
    {
        cout<<"MapViewOfFile failed :Error: "<<GetLastError()<<endl;
        return 0;
    }
     cout<<"MapViewOfFile Succeeded "<<endl;

     //3 Copy Your Data to the Mapped View Just got in Step 2  ( Shared place)
     CopyMemory(buffer,message,sizeof(message));

     //4. You are done writing, so unmap the View got in step 2
     bool bResult = UnmapViewOfFile(buffer);
     if(bResult == FALSE)
     {
        cout<<"UnmapViewOfFile failed :Error: "<<GetLastError()<<endl;
        return 0;
     }
     cout<<"UnmapViewOfFile Succeeded "<<endl;
    
    return 0;
}