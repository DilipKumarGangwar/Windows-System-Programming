#include<Windows.h>
#include<iostream>
using namespace std;

int main()
{

    //Local variables Declaration
    char *buffer = NULL;
    char message[1024] = "I am good, How are you ?";

    //1. OPen File Mapping
    HANDLE hFileMap = OpenFileMapping(
    FILE_MAP_ALL_ACCESS,
    FALSE,
    L"myfile"
    );

    if(hFileMap == NULL)
    {
        cout<<"OpenFileMapping failed :Error: "<<GetLastError()<<endl;
        return 0;
    }
     cout<<"OpenFileMapping Succeeded "<<endl;

    //2. Map the View to Process address space 

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

     //3 Read Your Data to the Mapped View Just got in Step 2  ( Shared place)
     cout<<"Data Received from parent = "<<buffer<<endl;

     //4. You are done reading, so unmap the View got in step 2
     bool bResult = UnmapViewOfFile(buffer);
     if(bResult == FALSE)
     {
        cout<<"UnmapViewOfFile failed :Error: "<<GetLastError()<<endl;
        return 0;
     }
     cout<<"UnmapViewOfFile Succeeded "<<endl;

     //5. Close the handle
     CloseHandle(hFileMap);
    return 0;
}