class Strategy{
    private:
    int data;
};

int main(){
    
    Strategy s;
    s.data = 10; // Error: 'data' is private within this context
    return 0;
}