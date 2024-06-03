#include <thread>
#include <mutex>

std::mutex mt;
int x{0};

void func() {
    std::lock_guard<std::mutex> lc_g(mt);
    while (x == 0) {
        x = 1 - x;
    }
}

int main()
{
    std::thread thr1{ func };
    std::thread thr2{ func };
	
	thr1.join();
	thr2.join();
}

