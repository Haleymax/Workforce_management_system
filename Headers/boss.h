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

//老板类
class Boss : public Worker{
public:
    Boss(int id , string name , int dId);

    //显示个人信息
    virtual void showInfo();

    //获取职工岗位名称
    virtual string getDeptName();
};

Boss::Boss(int id, std::string name, int dId) {
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

void Boss::showInfo() {
    cout << "职工编号： " << this->m_Id
         << " \t职工姓名： " << this->m_Name
         << " \t岗位：" << this->getDeptName()
         << " \t岗位职责：管理公司所有事务" << endl;
}

string Boss::getDeptName() {
    return string("总裁");
}