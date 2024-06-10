//
// Created by huang on 2024/6/6.
//


#pragma once   //��ֹͷ�ļ��ظ�����
#include "iostream"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include "fstream"
#define FILENAME "empFile.txt"

using namespace std;

class WorkerManager{
public:
    //���캯��
    WorkerManager();

    //��ʾ�˵�
    void Show_Menu();

    //�˳�ϵͳ
    void ExitSystem();

    //���ְ��
    void Add_Emp();

    //�����ļ�
    void save();

    //ͳ��ְ������
    int get_EmpNum();




    ~WorkerManager();

public:
    int m_EmpNum; //ְ������

    Worker ** m_EmpArray;  //��¼ְ������ָ��

    bool m_FileIsEmpty; //��־�ļ��Ƿ�Ϊ��
};

WorkerManager::WorkerManager() {

    ifstream ifs;  //����ļ���
    ifs.open(FILENAME,ios::in);

    //�ļ����������
    if (!ifs.is_open()){
        cout << "�ļ�������" << endl;
        //��ʼ������
        this->m_EmpNum = 0;

        //��ʼ������ָ��
        this->m_EmpArray = NULL;

        //��ʼ���ļ�Ϊ�ձ�־
        this->m_FileIsEmpty = true;

        ifs.close();
        return;
    }

    //�ļ����ڣ���û�м�¼
    char ch;
    ifs >> ch;
    if (ifs.eof()){
        cout << "�ļ�Ϊ��!" << endl;
        this->m_EmpNum = 0;
        this->m_FileIsEmpty = true;
        this->m_EmpArray = NULL;
        ifs.close();
        return;
    }

    //�ļ������������ݣ���ȡ����
    int num = this->get_EmpNum();
    cout << "ְ������Ϊ : " << num << endl;
    this->m_EmpNum = num; //����ְ������


}

WorkerManager::~WorkerManager() {
    if (this->m_EmpArray != NULL)
        delete[] this->m_EmpArray;
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


//���ְ����ʵ��
void WorkerManager::Add_Emp() {
    cout << "���������ӵ�ְ������" << endl;

    int addNum = 0;
    cin >> addNum;

    if (addNum > 0){
        //���ÿɱ䳤�������ʽ������ְ�����¿���һ��������������ԭ���ľ�����

        //�����¿ռ�Ĵ�С
        int newSize = this->m_EmpNum + addNum;

        //�����¿ռ�
        Worker ** newSpace = new Worker * [newSize];

        //��ԭ�ռ������ݴ�ŵ��¿ռ���
        if (this->m_EmpNum != NULL){
            for (int i = 0; i < this->m_EmpNum; ++i) {
                newSpace[i] = this->m_EmpArray[i];
            }
        }

        //����������
        for (int i = 0; i < addNum; ++i) {
            int id;
            string name;
            int dSelect;

            cout<< "������� " << i + i << " ����ְ����� ��" <<endl;
            cin >> id;

            cout<< "������� " << i + 1 << "����ְ������ : " <<endl;
            cin >> name;

            cout << "��ѡ��g��ְ���ĸ�λ : " << endl;
            cout << "1����ְͨ��" <<endl;
            cout << "2������" << endl;
            cout << "3���ϰ�" << endl;
            cin >> dSelect;

            //������ְ��
            Worker *worker = NULL;
            switch (dSelect) {
                case 1:   //��ְͨ��
                    worker = new Employee(id,name,1);
                    break;
                case 2: //����
                    worker = new Manager(id,name,2);
                    break;
                case 3: //�ϰ�
                    worker = new Boss(id,name,3);
                    break;
                default:
                    break;
            }

            newSpace[this->m_EmpNum + i] = worker;
        }
        //�ͷ�ԭ�пռ�
        delete[] this->m_EmpArray;

        //����ϵͳ��ְ����Ϣ����ָ���¿���������
        this->m_EmpArray = newSpace;

        //����ְ������
        this->m_EmpNum = newSize;

        //����ְ����Ϊ�յı�־
        this->m_FileIsEmpty = false;

        //��ʾ��ӳɹ�
        cout << "�ɹ����" << addNum << "����ְ����" << endl;

        //������д���ļ���
        this->save();
    } else{
        cout << "��������" <<endl;
    }

    system("pause");
    system("cls");
}


//�˳�ϵͳ
void WorkerManager::ExitSystem() {
    cout << "��ӭ�´�ʹ��" <<endl;
    system("pause");
    exit(0);
}

void WorkerManager::save() {
    ofstream ofs;  //�����ļ���
    ofs.open(FILENAME,ios::out);

    for (int i = 0; i < this->m_EmpNum; ++i) {
        ofs << this->m_EmpArray[i]->m_Id << " "
            << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_DeptId << endl;
    }
    ofs.close();
}

int WorkerManager::get_EmpNum() {
    ifstream ifs;
    ifs.open(FILENAME,ios::in);

    int id;
    string name;
    int dId;

    int num = 0;

    while (ifs >> id && ifs >> name && ifs >> dId){
        //��¼����
        num++;
    }
    ifs.close();

    return num;
}