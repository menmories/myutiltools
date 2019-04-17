#ifndef __SCARAB_THREAD_H__
#define __SCARAB_THREAD_H__

#include <windows.h>
#include <process.h>
namespace SCarabLib
{
	class SThread
	{
	public:
		SThread(_beginthreadex_proc_type callback, void* args);
		~SThread();
	public:
		void BeginThread();

		DWORD ResumeThread();

		DWORD SuspendThread();

		DWORD WaitThreadQuit(DWORD dwTimeout = INFINITE);

		void ExitThread();

		int PostThreadMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
	private:
		unsigned int m_nThreadId;

		HANDLE m_hThread;

		bool m_bCreateStatus;
	};

	class SCriticalSection
	{
	public:
		SCriticalSection();
		~SCriticalSection();

	public:
		void Lock();
		void UnLock();
	private:
		CRITICAL_SECTION m_criticalSection;
	};
}


#endif	//__SCARAB_THREAD_H__