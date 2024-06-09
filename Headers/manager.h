//
// Created by huang on 2024/6/9.
//

#ifndef WORKFORCE_MANAGEMENT_SYSTEM_MANAGER_H
#define WORKFORCE_MANAGEMENT_SYSTEM_MANAGER_H

#endif //WORKFORCE_MANAGEMENT_SYSTEM_MANAGER_H

#pragma once
#include "iostream"
#include "worker.h"

using namespace std;


//������
class Manager :public Worker{
public:
    Manager(int id , string name , int dId);

    //��ʾ������Ϣ
    virtual void showInfo();

    //��ȡְ����λ����
    virtual string getDeptName();
};

Manager::Manager(int id, std::string name, int dId) {
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}


void Manager::showInfo() {
    cout << "ְ����ţ� " << this->m_Id
         << " \tְ�������� " << this->m_Name
         << " \t��λ��" << this->getDeptName()
         << " \t��λְ������ϰ彻��������,���·������Ա��" << endl;
}

string Manager::getDeptName() {
    return string("����");
}