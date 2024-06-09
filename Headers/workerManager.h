//
// Created by huang on 2024/6/6.
//


#pragma once   //��ֹͷ�ļ��ظ�����
#include "iostream"
#include "Headers/worker.h"

using namespace std;

class WorkerManager{
public:
    //���캯��
    WorkerManager();

    //��ʾ�˵�
    void Show_Menu();

    //�˳�ϵͳ
    void ExitSystem();




    ~WorkerManager();

public:
    int m_EmpNum; //ְ������

    Worker ** m_EmpArray;  //��¼ְ������ָ��
};

WorkerManager::WorkerManager() {

}

WorkerManager::~WorkerManager() {

}
void WorkerManager::Show_Menu()
{
    cout << "********************************************" << endl;
    cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
    cout << "*************  0.�˳��������  *************" << endl;
    cout << "*************  1.����ְ����Ϣ  *************" << endl;
    cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
    cout << "*************  3.ɾ����ְְ��  *************" << endl;
    cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
    cout << "*************  5.����ְ����Ϣ  *************" << endl;
    cout << "*************  6.���ձ������  *************" << endl;
    cout << "*************  7.��������ĵ�  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

WorkerManager::WorkerManager() {
    //��ʼ������
    this->m_EmpNum = 0;

    this->m_EmpArray = NULL;
}