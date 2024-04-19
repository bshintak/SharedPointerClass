#include "Shared.h"

int main() {
    Shared<int> s1;

    Shared<int> s2(s1);
    Shared<int> s4(std::move(s1));

    Shared<int> s3;
    s3 = s2;

    Shared<int> s5;
    s5 = s2;

    std::cout << s1.getCount() << std::endl;
}