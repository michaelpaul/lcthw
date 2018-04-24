#!/usr/bin/env bats

@test "without arguments" {
    run ./logfind
    [ "$status" -eq 2 ]
    [ "$output" = "usage: ./logfind [-o] word..." ]
}

@test "no matches" {
    run ./logfind isso non existe!
    [ "$status" -ne 0 ]
}

@test "and: match all words" {
    run ./logfind hello foo
    [ "$status" -eq 0 ]
    echo "$output" | grep "./foo.txt" 
}

@test "or: match any word" {
    run ./logfind -o bar only
    [ "$status" -eq 0 ]
    echo "$output" | grep "./bar.txt" 
}
