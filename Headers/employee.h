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
    //构造函数
    Employee(int id , string name , int dId);

    //显示个人信息
    virtual void showInfo();

    //获取职工岗位信息
    virtual string getDeptName();
};


Employee::Employee(int id, string name, int dId) {
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

void Employee::showInfo() {
    cout << "职工编号： " << this->m_Id
         << " \t职工姓名： " << this->m_Name
         << " \t岗位：" << this->getDeptName()
         << " \t岗位职责：完成经理交给的任务" << endl;

}

string Employee::getDeptName() {
    return string("员工");
}
