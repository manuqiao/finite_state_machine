#include "FSMstate.h"

FSMstate::FSMstate(int iStateID,unsigned usTransitions)
{
	if(!usTransitions) //���������ת������Ϊ0������Ϊ1
		m_usNumberOfTransition=1;
	else
		m_usNumberOfTransition=usTransitions;
	//��״̬��ID��������
	m_iStateID=iStateID;
	//�����ڴ�ռ�
	try
	{
		m_piInputs=new int[m_usNumberOfTransition];
		for(int i=0;i<m_usNumberOfTransition;++i)
			m_piInputs[i]=0;
	}
	catch(...)
	{
		throw;
	}
	try
	{
		m_piOutputState=new int[m_usNumberOfTransition];
		for(int i=0;i<m_usNumberOfTransition;++i)
			m_piOutputState[i]=0;
	}
	catch(...)
	{
		delete [] m_piInputs;
		throw;
	}
}

FSMState::~FSMState()
{
	delete [] m_piInputs;
	delete [] m_piOutputState;
}

void FSMstate::AddTransition(int iInput,int iOutputID)
{
	for(int i=0;i<m_usNumberOfTransitions;++i)
		if(!m_piOutputState[i]) break;
	if(i<m_usNumberOfTransition)
	{
		m_piOutputState[i]=iOutputID;
		m_piInputs[i]=iInput;
	}
}

void FSMstate::DeleteTransition(int iOutputID)
{
	// ����ÿһ�����״̬
	for(int i=0;i<m_usNumberOfTransition;++i)
	{
		//����ҵ����״̬���˳�ѭ��
		if(m_piOutputState[i]==iOutputID)
			break;
	}
	//���û���ҵ����״̬������
	if(i>=m_usNumberOfTransition)
		return;
	//�����״̬��������0
	m_piInputs[i]=0;
	m_piOutputState[i]=0;
	//��ɾ�������״̬�ĺ�������״̬ǰ��
	for(;i<(m_usNumberOfTransition-1);++i)
	{
		if(!m_piOutputState[i])
			break;
		m_piInputs[i]=m_piInputs[i+1];
		m_piOutputState[i]=m_piOutputState[i+1];
	}
	//���������״̬��0
	m_piInputs[i]=0;
	m_piOutputState[i]=0;
}
