# Plazza

## Description

Plazza is a multi-threaded C++ Scraper designed to explore files and find 3 differents things:
- Ip address
- Phone number
- Email address

Plazza uses multi process communications. Basically it forks itself, the very first copy is the manager and directs everyone output. Then it distributes files and tasks between each process. Each process then gives work to each of their Thread pool.

Commands are written like so :
```index.htm EMAIL_ADDRESS; company.csv memo.txt PHONE_NUMBER```

## Usage
You should build a ```commands.txt``` file where you put all the task you want so you can easily launch it like so :

```make re && cat commands.txt | ./plazza NB_THREADS > output.txt```
where NB_THREADS is the number of threads per process 

### Credits
*Developed by Alexis Papadimitriou (Socket and inter process communication) and me (Thread Pool, abstraction, scraping)*