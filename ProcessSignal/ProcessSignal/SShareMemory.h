
#ifndef __SCARAB_SHARE_MEMORY_H__
#define __SCARAB_SHARE_MEMORY_H__

#include <Windows.h>
#include <atlbase.h>
#include <atlstr.h>
class SShareMemory
{
public:
	SShareMemory(const CString& strFileMappingName);
	~SShareMemory();

	bool Create();

	void Write(char* buf, int len);

	void Read(char* buf, int len);

	void Destroy();
private:
	HANDLE m_hFileMapping;
	LPVOID m_lpSharMemory;
	CString m_strMappingFileName;
};

#endif