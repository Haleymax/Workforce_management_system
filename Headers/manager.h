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


//经理类
class Manager :public Worker{
public:
    Manager(int id , string name , int dId);

    //显示个人信息
    virtual void showInfo();

    //获取职工岗位名称
    virtual string getDeptName();
};

Manager::Manager(int id, std::string name, int dId) {
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}


void Manager::showInfo() {
    cout << "职工编号： " << this->m_Id
         << " \t职工姓名： " << this->m_Name
         << " \t岗位：" << this->getDeptName()
         << " \t岗位职责：完成老板交给的任务,并下发任务给员工" << endl;
}

string Manager::getDeptName() {
    return string("经理");
}