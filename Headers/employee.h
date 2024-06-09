//
// Created by huang on 2024/6/7.
//

#ifndef STUDY_EMPLOYEE_H
#define STUDY_EMPLOYEE_H

#endif //STUDY_EMPLOYEE_H

#pragma once
#include "iostream"
#include "worker.h"

using namespace std;


class Employee : public Worker{
public:
    //���캯��
    Employee(int id , string name , int dId);

    //��ʾ������Ϣ
    virtual void showInfo();

    //��ȡְ����λ��Ϣ
    virtual string getDeptName();
};


Employee::Employee(int id, string name, int dId) {
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

void Employee::showInfo() {
    cout << "ְ����ţ� " << this->m_Id
         << " \tְ�������� " << this->m_Name
         << " \t��λ��" << this->getDeptName()
         << " \t��λְ����ɾ�����������" << endl;

}

string Employee::getDeptName() {
    return string("Ա��");
}
