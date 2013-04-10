#include "FSMstate.h"

FSMstate::FSMstate(int iStateID,unsigned usTransitions)
{
	if(!usTransitions) //如果给出的转换数量为0，就算为1
		m_usNumberOfTransition=1;
	else
		m_usNumberOfTransition=usTransitions;
	//将状态的ID保存起来
	m_iStateID=iStateID;
	//分配内存空间
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
	// 遍历每一个输出状态
	for(int i=0;i<m_usNumberOfTransition;++i)
	{
		//如果找到输出状态，退出循环
		if(m_piOutputState[i]==iOutputID)
			break;
	}
	//如果没有找到输出状态，返回
	if(i>=m_usNumberOfTransition)
		return;
	//将输出状态的内容置0
	m_piInputs[i]=0;
	m_piOutputState[i]=0;
	//被删除的输出状态的后面的输出状态前移
	for(;i<(m_usNumberOfTransition-1);++i)
	{
		if(!m_piOutputState[i])
			break;
		m_piInputs[i]=m_piInputs[i+1];
		m_piOutputState[i]=m_piOutputState[i+1];
	}
	//最后面的输出状态置0
	m_piInputs[i]=0;
	m_piOutputState[i]=0;
}
