#include <memory>
#include <iostream>
using namespace std;

class NetflixAccount {
public:
    void watch() { std::cout << "Watching Stranger Things\n"; }
};

int main() {
    std::shared_ptr<NetflixAccount> mom = std::make_shared<NetflixAccount>();
    std::shared_ptr<NetflixAccount> dad = mom; // Both share the same account
    shared_ptr<NetflixAccount> son = mom;
    
    mom->watch(); // Output: Watching Stranger Things
    std::cout << "Users: " << mom.use_count() << "\n"; // Output: Users: 3

    dad.reset(); // Dad stops using the account
    std::cout << "Users: " << mom.use_count() << "\n"; // Output: Users: 2
    
    son.reset();
    std::cout << "Users: " << mom.use_count() << "\n"; // Output: Users: 1
    
    return 0; // Account cancels when 'mom' goes out of scope
}
