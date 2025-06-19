#! /bin/bash
make clean

cargo build --release

mv target/release/librust_video.so rust_video.so

make

clear

echo "Server running on port 8080"

./server -p 8080