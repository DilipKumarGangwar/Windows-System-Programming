For data Sharing between 2 or more processes, we use this technique

What is File Mapping:
https://learn.microsoft.com/en-us/windows/win32/memory/file-mapping


Creating File Mapping Object in RAM :
============================================
CreateFileMapping():
Creates or opens a named or unnamed file mapping object for a specified file.

Return Value: 
If the function succeeds, the return value is a handle to the newly created file mapping object
If the function fails, the return value is NULL.

HANDLE CreateFileMappingA(
  [in]           HANDLE                hFile,
  [in, optional] LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
  [in]           DWORD                 flProtect,
  [in]           DWORD                 dwMaximumSizeHigh,
  [in]           DWORD                 dwMaximumSizeLow,
  [in, optional] LPCSTR                lpName
);


Creating a File View: MapViewOfFile()
==========================
To map the data from a file to the virtual memory of a process, you must create a view of the file. The MapViewOfFile and MapViewOfFileEx functions use the file mapping object handle returned by CreateFileMapping to create a view of the file or a portion of the file in the process's virtual address space. These functions fail if the access flags conflict with those specified when CreateFileMapping created the file mapping object.


Return Value:
The MapViewOfFile function returns a pointer to the starting address from File Mapped object from where the file view is created for the process 
On Failure: Returns NULL

By dereferencing a pointer in the range of addresses specified in MapViewOfFile, an application can read data from the file and write data to the file. Writing to the file view results in changes to the file mapping object. The actual writing to the file on disk is handled by the system

LPVOID MapViewOfFile(
  [in] HANDLE hFileMappingObject,
  [in] DWORD  dwDesiredAccess,
  [in] DWORD  dwFileOffsetHigh,
  [in] DWORD  dwFileOffsetLow,
  [in] SIZE_T dwNumberOfBytesToMap
);



UnmapViewOfFile():
=====================
Unmaps a mapped view of a file from the calling process's address space.

Return Value:
If the function succeeds, the return value is nonzero.
If the function fails, the return value is zero.

BOOL UnmapViewOfFile(
  [in] LPCVOID lpBaseAddress
);


OpenFileMapping():
===========================
Opens a named file mapping object.

HANDLE OpenFileMapping(
  [in] DWORD  dwDesiredAccess,
  [in] BOOL   bInheritHandle,
  [in] LPCSTR lpName
);


If the function succeeds, the return value is an open handle to the specified file mapping object.
If the function fails, the return value is NULL. 

Resources:
https://www.youtube.com/watch?v=Dk6v8wIpJWk&t=208s
https://www.youtube.com/watch?v=QEpdiorTLIg&t=920s