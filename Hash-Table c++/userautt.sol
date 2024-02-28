// SPDX-License-Identifier: MIT
pragma solidity ^0.8.19;

contract UserAutentication {

    mapping(address => bool) public users;

    event NewUser(address indexed user);

    function userRegistration(address wallet) public returns(bool) {
        users[wallet] = true;
        emit NewUser(wallet);
        return true;
    }

}
