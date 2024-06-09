//
// Created by huang on 2024/6/9.
//

#ifndef WORKFORCE_MANAGEMENT_SYSTEM_BOSS_H
#define WORKFORCE_MANAGEMENT_SYSTEM_BOSS_H

#endif //WORKFORCE_MANAGEMENT_SYSTEM_BOSS_H

#pragma once
#include "iostream"
#include "worker.h"

using namespace std;

//�ϰ���
class Boss : public Worker{
public:
    Boss(int id , string name , int dId);

    //��ʾ������Ϣ
    virtual void showInfo();

    //��ȡְ����λ����
    virtual string getDeptName();
};

Boss::Boss(int id, std::string name, int dId) {
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

void Boss::showInfo() {
    cout << "ְ����ţ� " << this->m_Id
         << " \tְ�������� " << this->m_Name
         << " \t��λ��" << this->getDeptName()
         << " \t��λְ�𣺹���˾��������" << endl;
}

string Boss::getDeptName() {
    return string("�ܲ�");
}