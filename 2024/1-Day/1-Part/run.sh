g++ -o main main.cpp 

if [ -f main ]; then 
    ./main < input
    rm main 
fi