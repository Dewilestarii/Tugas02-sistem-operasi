#include  <stdio.h>
#include  <windows.h>

  int main(VOID)
  {
  STARTUPINFO si;
  PROCESS_INFORMATION pi;
  /* allocate memory */
  ZeroMemory(&si, sizeof(si));
  si.cb = sizeof(si);
  ZeroMemory(&pi, sizeof(pi));

  /* create child process */
  if (!CreateProcess(NULL, /* use command line */
  "C:\\WINDOWS\\system32\\mspaint.exe", /* command */
  NULL, /* don't inherit process handle */
  NULL, /* don't inherit thread handle */
  FALSE, /* disable handle inheritance */
  0, /* no creation flag */
  NULL, /* use parent's environment block */
  NULL, /* use parent's existing directory */
  &si,
  &pi))
    {
      fprintf(stderr, "Create Process Failed");
      return -1;
    }

    /*parents will wait for the child to complete */
    WaitForSingleObject(pi.hProcess, INFINITE);
    printf("Child Complete");
    printf("Dewi Lestari - 14201191");

    /* close handles */
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}
