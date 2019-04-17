#include "SMsgQueue.h"
#pragma comment(lib, "mqrt.lib")


SCarabLib::SMsgQueue::SMsgQueue()
{
}


SCarabLib::SMsgQueue::~SMsgQueue()
{
}

HRESULT SCarabLib::SMsgQueue::CreateQueue(LPTSTR lpName, DWORD dwLength)
{
	return ::MQCreateQueue(NULL, &m_props, lpName, &dwLength);
}

HRESULT SCarabLib::SMsgQueue::OpenQueue(LPTSTR lpName)
{
	return ::MQOpenQueue(lpName, MQ_PEEK_ACCESS | MQ_SEND_ACCESS | MQ_MOVE_ACCESS | MQ_RECEIVE_ACCESS, MQ_DENY_NONE, &m_queueHandle);
}

HRESULT SCarabLib::SMsgQueue::ReceiveMessage(DWORD dwTimeout, DWORD dwAction)
{
	return MQReceiveMessage(m_queueHandle, dwTimeout, dwAction, &m_msgProps, NULL, NULL, NULL, MQ_NO_TRANSACTION);
}

HRESULT SCarabLib::SMsgQueue::SendMessage()
{
	return ::MQSendMessage(m_queueHandle, &m_msgProps, MQ_NO_TRANSACTION);
}

void SCarabLib::SMsgQueue::CloseQueue()
{
	MQCloseQueue(m_queueHandle);
}
