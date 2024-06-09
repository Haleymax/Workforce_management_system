//
// Created by huang on 2024/6/7.
//

#ifndef STUDY_WORKER_H
#define STUDY_WORKER_H

#endif //STUDY_WORKER_H

#pragma once
#include "iostream"
#include "string"

using namespace std;

//职工抽象类
class Worker{
public:

    //显示个人信息
    virtual void showInfo() = 0;

    //获取岗位名称
    virtual string getDeptName() = 0;

public:
    int m_Id;  //职工编号
    string m_Name;  //职工姓名
    int m_DeptId;  //职工所在部门
};