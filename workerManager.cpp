//
// Created by huang on 2024/6/6.
//

#include "Headers/workerManager.h"
#include "Headers/worker.h"
#include "Headers/employee.h"



int main(){

    //���԰���
    Worker * worker = NULL;
    worker = new Employee(1, "Haley", 1);
    worker->showInfo();

    //ʵ���������߶���
    WorkerManager w;

    int choice = 0;  //���ڴ洢�û���ѡ��

    while (true){
        w.Show_Menu();
        cout << "����������ѡ�� :" <<endl;
        cin >> choice;  //�����û���ѡ��

        switch (choice) {
            case 0:     //�˳�ϵͳ
                w.ExitSystem();
                break;
            case 1:     //����Ա��
                break;
            case 2:     //��ʾְ��
                break;
            case 3:     //ɾ��ְ��
                break;
            case 4:     //�޸�ְ��
                break;
            case 5:     //����ְ��
                break;
            case 6:     //����ְ��
                break;
            case 7:     //����ĵ�
                break;
            default:
                system("cls");
                break;
        }
    }



}

//�˳�ϵͳ
void WorkerManager::ExitSystem() {
    cout << "��ӭ�´�ʹ��" <<endl;
    system("pause");
    exit(0);
}