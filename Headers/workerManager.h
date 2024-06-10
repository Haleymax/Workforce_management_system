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

    //��ʼ��Ա��
    void init_Emp();

    //��ʾְ����Ϣ
    void show_Emp();

    //ɾ��ְ��
    void Del_Emp();

    //����ְ������ж��Ƿ���ڣ������ڷ���ְ���������е�λ�ã������ڷ���-1
    int IsExist(int id);

    //�޸�ְ��
    void Mod_Emp();

    //����ְ��
    void Find_Emp();

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

    //����ְ��������������
    this->m_EmpArray = new Worker * [this->m_EmpNum];
    //��ʼ��ְ������
    init_Emp();
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


void WorkerManager::init_Emp() {
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    cout<<"��ʼ��" << endl;
    int id;
    string name;
    int dId;
    this->m_FileIsEmpty = false;

    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> dId){
        Worker *worker = NULL;

        //���ݲ�ͬ�Ĳ���id���н�ɫ����
        if (dId == 1) {   //��ְͨ��
            worker = new Employee(id,name,dId);
        } else if (dId == 2) {  //����
            worker = new Manager(id,name,dId);
        } else if (dId == 3) { //�ϰ�
            worker = new Boss(id,name,dId);
        }

        //�������õĶ���������������
        this->m_EmpArray[index++] = worker;

    }

}

//��ʾְ��
void WorkerManager::show_Emp() {
    if (this->m_FileIsEmpty)
        cout << "�ļ������ڻ��¼Ϊ��" << endl;
    else
        for (int i = 0; i < m_EmpNum; ++i) {
            //����������ÿ����Ӧְ������ʾ������Ϣ�ĺ���
            this->m_EmpArray[i]->showInfo();
        }
    system("pause");
    system("cls");
}

//�ж�ְ���Ƿ����
int WorkerManager::IsExist(int id) {
    int index = -1;
    for (int i = 0; i < this->m_EmpNum; ++i) {
        if (this->m_EmpArray[i]->m_Id == id){
            index = i;
            break;
        }
    }
    return index;
}


//ɾ��ְ��
void WorkerManager::Del_Emp() {
    if (this->m_FileIsEmpty)
        cout << "�ļ������ڻ��¼Ϊ�� ! " << endl;
    else{
        //��ְ�����ɾ��
        cout<< "��������Ҫɾ����ְ����" << endl;

        int id = 0;
        cin >> id;


        int index  = this->IsExist(id);

        if (index != -1){  //��ʾ��Ҫɾ����ְ���Ǵ��ڵ�
            for (int i = index; i < this->m_EmpNum -1; ++i) {
                this->m_EmpArray[i] = this->m_EmpArray[i+1];
                //��Ҫɾ���Ľڵ�����Ԫ��������ǰ�ƶ����Ǽ���ʵ��ɾ��
            }
            this->m_EmpNum--;

            this->save(); //ɾ�����ݺ�ͬ�����ļ���
            cout << "ɾ���ɹ�!" <<endl;
        } else{
            cout << "ɾ��ʧ�ܣ�"<< endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::Mod_Emp() {
    if (this->m_FileIsEmpty)
        cout<< "�ļ������ڻ��¼Ϊ��!" <<endl;
    else{
        cout<< "�������޸�ְ���ı��" <<endl;
        int id;
        cin >> id;

        int ret = this->IsExist(id);
        if (ret != -1){   //��ʾ��Ҫ�޸ĵ�ְ������

            delete this->m_EmpArray[ret];  //ɾ��ԭ����ְ����Ϣ

            int newId = 0;
            string newName = "";
            int dSelect = 0;

            cout << "�鵽: " << id << "��Ա������������ְ����" << endl;
            cin >> newId;

            cout << "������������ ��" << endl;
            cin >> newName;

            cout << "�������λ �� " << endl;
            cout << "1����ְͨ��" <<endl;
            cout << "2������" <<endl;
            cout << "3���ϰ�" <<endl;
            cin >> dSelect;

            Worker * worker = NULL;
            switch (dSelect) {
                case 1:
                    worker = new Employee(newId,newName,dSelect);
                    break;
                case 2:
                    worker = new Manager(newId,newName,dSelect);
                    break;
                case 3:
                    worker = new Boss(newId,newName,dSelect);
                    break;
                default:
                    break;
            }

            //�������ݵ�������
            this->m_EmpArray[ret] = worker;

            cout << "�޸ĳɹ�!" <<endl;

            //��������
            this->save();
        } else{
            cout << "���޴���" << endl;
        }

    }

    system("pause");
    system("cls");
}

//����Ա��
void WorkerManager::Find_Emp() {
    if (this->m_FileIsEmpty)
        cout << "�ļ������ڻ��¼Ϊ��" <<endl;
    else{
        cout << "��������ҷ���" << endl;
        cout << "1.��ְ����Ų���" <<endl;
        cout << "2.����������" << endl;


        int select = 0;
        cin >> select;

        if (select == 1){   //��ְ�����Ų���
            int id;
            cout << "��������ҵ�ְ�����" << endl;
            cin >> id;

            int ret = IsExist(id);
            if (ret != -1){
                cout << "���ҳɹ�����ְ����Ϣ���� : " << endl;
                this->m_EmpArray[ret]->showInfo();
            } else
                cout << "���޴���" <<endl;
        } else if (select == 2) {  //����������
            string name;
            cout << "��������ҵ�����" << endl;

            cin >> name;

            bool flag = false; //���ҵ��ı�־
            for (int i = 0; i < this->m_EmpNum; ++i) {
                if (this->m_EmpArray[i]->m_Name == name){
                    cout << "���ҳɹ���ְ�����Ϊ��"
                         << m_EmpArray[i]->m_Id
                         <<" �ŵ���Ϣ���� �� "<<endl;

                    flag = true;

                    this->m_EmpArray[i]->showInfo();
                }
            }
            if (flag == false){
                //����ʧ��
                cout << "���޴���" << endl;
            }
        }
        system("pause");
        system("cls");
    }
}