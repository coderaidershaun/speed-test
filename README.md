### Instructions

## Step 1 - Clone Repo

Clone and cd into the repository:

```shell
git clone git clone https://github.com/coderaidershaun/speed-test-sieve-eratosthenes.git speed_test
cd speed_test
```

## Step 2 - Spin Up a Machine

Create an Ubuntu 22.04 instance on AWS as EC2 or use your preferred approach. 

The example shown on YouTube uses a T2 - Medium machine (x86 architecture).

If you prefer, you can just run this locally but commands will be different if using Windows so some experience/googling/chatgippitying might be necessary.

## Step 3 - Prepare Ubuntu on EC2

3 - Below Are the instructions for installing languages. Start with:

```shell
sudo apt update
sudo apt upgrade -y
```

C and C++:

```shell
sudo apt install build-essential
```

Go:

```shell
sudo apt update
wget https://golang.org/dl/go1.17.2.linux-amd64.tar.gz
tar -xvf go1.17.2.linux-amd64.tar.gz
sudo mv go /usr/local
export GOROOT=/usr/local/go
export GOPATH=$HOME/go
export PATH=$GOPATH/bin:$GOROOT/bin:$PATH
source ~/.profile
go version
```

Python:

```shell
sudo apt update
python3 --version
sudo apt install python3
```

Node JS:

```shell
sudo apt update
curl -fsSL https://deb.nodesource.com/setup_16.x | sudo -E bash -
sudo apt-get install -y nodejs
```

Typescript:

```shell
sudo apt update
sudo npm install -g typescript ts-node
```

Rust:

```shell
sudo apt update
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
1
```

### Build and Test

C:

```shell
gcc test_memory.c -o test_memory
gcc test_speed.c -o test_speed
./test_speed
./test_memory
```

C++:

```shell
g++ -std=c++11 test.cpp -o test
./test
```


Go:

```shell
cd go_test
go mod init speed
go build
./speed
```

Python:

```shell
cd python_test
python3 main.py
```

Javascript:

```shell
cd javascript_test
node main.js
```

Typescript:

```shell
cd typescript_test
node main.ts
```