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

//ְ��������
class Worker{
public:

    //��ʾ������Ϣ
    virtual void showInfo() = 0;

    //��ȡ��λ����
    virtual string getDeptName() = 0;

public:
    int m_Id;  //ְ�����
    string m_Name;  //ְ������
    int m_DeptId;  //ְ�����ڲ���
};