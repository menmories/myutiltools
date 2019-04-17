
#ifndef __SCARAB_MSG_QUEUE_H__
#define __SCARAB_MSG_QUEUE_H__
#include <Windows.h>
#include <Mq.h>
#include <atlbase.h>
#include <atlstr.h>

namespace SCarabLib
{
	class SMsgQueue
	{
	public:
		SMsgQueue();
		~SMsgQueue();
	public:
		HRESULT CreateQueue(LPTSTR lpName, DWORD dwLength);

		HRESULT OpenQueue(LPTSTR lpName);

		HRESULT ReceiveMessage(DWORD dwTimeout, DWORD dwAction = MQ_ACTION_PEEK_CURRENT);

		HRESULT SendMessage();

		void CloseQueue();
	private:
		CString m_strQueueName;
		MQQUEUEPROPS m_props;
		MQMSGPROPS m_msgProps;
		QUEUEHANDLE m_queueHandle;
	};
}



#endif	//__SCARAB_MSG_QUEUE_H__