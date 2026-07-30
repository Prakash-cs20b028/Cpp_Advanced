#include <memory>
#include <iostream>

class LibraryBook {
public:
    void read() { std::cout << "Reading...\n"; }
};

int main() {
    std::shared_ptr<LibraryBook> book = std::make_shared<LibraryBook>();
    std::weak_ptr<LibraryBook> waitlist = book; // Join waitlist

    if (auto borrowed = waitlist.lock()) { // Check if book is available
        borrowed->read(); // Output: Reading...
    } else {
        std::cout << "Book is checked out\n";
    }

    book.reset(); // Return the book
    if (waitlist.expired()) { // Check if resource is gone
        std::cout << "Book is no longer available\n"; // Output: Book is no longer available
    }
    return 0;
}
