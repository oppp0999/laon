#include <iostream>

// 작업자 인터페이스
class IWorker {
public:
    virtual void doWork() = 0;
};

// 작업자 클래스
class Worker : public IWorker {
public:
    void doWork() override {
        std::cout << "Worker performs tasks." << std::endl;
    }
};

// 클라이언트 클래스
class Client {
private:
    IWorker* worker;

public:
    Client(IWorker* w) : worker(w) {}

    void executeTasks() {
        worker->doWork();
    }
};

int main() {
    Worker worker;
    Client client(&worker);
    client.executeTasks();

    return 0;
}