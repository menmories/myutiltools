#include "SShareMemory.h"



SShareMemory::SShareMemory(const CString& strFileMappingName)
	: m_strMappingFileName(strFileMappingName)
{
}


SShareMemory::~SShareMemory()
{
}

bool SShareMemory::Create()
{
	m_hFileMapping = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, m_strMappingFileName);
	if (!m_hFileMapping)
	{
		m_hFileMapping = ::CreateFileMapping(m_hFileMapping, nullptr, PAGE_READWRITE, 0, 0, m_strMappingFileName);
		if (!m_hFileMapping)
		{
			return false;
		}
	}
	m_lpSharMemory = MapViewOfFile(m_hFileMapping, FILE_MAP_ALL_ACCESS, 0, 0, 0);
	if (!m_lpSharMemory)
	{
		return false;
	}
	return true;
}

void SShareMemory::Write(char * buf, int len)
{
	memcpy(m_lpSharMemory, buf, len);
}

void SShareMemory::Read(char * buf, int len)
{
	memcpy(buf, m_lpSharMemory, len);
}

void SShareMemory::Destroy()
{
	UnmapViewOfFile(m_lpSharMemory);
	::CloseHandle(m_hFileMapping);
}
