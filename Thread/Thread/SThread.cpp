#include "SThread.h"



SCarabLib::SThread::SThread(_beginthreadex_proc_type callback, void* args)
	: m_nThreadId(0)
	, m_hThread(NULL)
{
	m_hThread = (HANDLE)::_beginthreadex(NULL, 0, callback, args, CREATE_SUSPENDED, &m_nThreadId);
	if (!m_nThreadId)
	{
		m_bCreateStatus = false;
	}
	else
	{
		m_bCreateStatus = true;
	}
}


SCarabLib::SThread::~SThread()
{
	if (m_bCreateStatus)
	{
		::CloseHandle(m_hThread);
	}
}

void SCarabLib::SThread::BeginThread()
{
	::ResumeThread(m_hThread);
}

DWORD SCarabLib::SThread::ResumeThread()
{
	return ::ResumeThread(m_hThread);
}

DWORD SCarabLib::SThread::SuspendThread()
{
	return ::SuspendThread(m_hThread);
}

DWORD SCarabLib::SThread::WaitThreadQuit(DWORD dwTimeout)
{
	return ::WaitForSingleObject(m_hThread, dwTimeout);
}

void SCarabLib::SThread::ExitThread()
{
	TerminateThread(m_hThread, -1);
}

int SCarabLib::SThread::PostThreadMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return ::PostThreadMessage(m_nThreadId, uMsg, wParam, lParam);
}

SCarabLib::SCriticalSection::SCriticalSection()
{
	InitializeCriticalSection(&m_criticalSection);
}

SCarabLib::SCriticalSection::~SCriticalSection()
{
	DeleteCriticalSection(&m_criticalSection);
}

void SCarabLib::SCriticalSection::Lock()
{
	::EnterCriticalSection(&m_criticalSection);
}

void SCarabLib::SCriticalSection::UnLock()
{
	::LeaveCriticalSection(&m_criticalSection);
}
