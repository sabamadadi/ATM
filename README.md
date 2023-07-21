# ATM

## REGISTER
### Input Format:
REGISTER USERNAME TIMESTAMP

### Explanation:
A user with the name USERNAME registers in the ATM at the TIMESTAMP.

### Output:
- If a user with the name USERNAME has already registered at the time of registration, print the message Duplicate User!
- Otherwise, print the message Registered Successfully.

## DEPOSIT
### Input Format:
DEPOSIT USERNAME AMOUNT TIMESTAMP

### Explanation:
The amount of AMOUNT currency is added to the account of the user with the name USERNAME at the TIMESTAMP.

### Output:
- If there is no user with the name USERNAME at the time of increasing the balance, print the message No Such User Found!
- Otherwise, print the balance of the account of the user with the name USERNAME after increasing the balance.

## WITHDRAW
### Input Format:
WITHDRAW USERNAME AMOUNT TIMESTAMP

### Explanation:
The amount of AMOUNT currency is withdrawn from the account of the user with the name USERNAME at the TIMESTAMP, and for that amount, the equivalent amount of currency is deducted from the banknotes inside the ATM.

### Output:
- If there is no user with the name USERNAME at the time of withdrawal, print the message No Such User Found!
- If the amount of AMOUNT is more than 200 currency units, print the message Maximum Amount Exceeded!
- If the balance of the account with the name USERNAME was less than the amount of AMOUNT at the time of withdrawal, print the message Not Enough Fund!
- If we could not pay the requested amount with the banknotes inside the machine, print the message Not Enough Banknotes!
- Otherwise, print the balance of the account of the user with the name USERNAME after withdrawal.

## TRANSFER
### Input Format:
TRANSFER SENDER_USERNAME RECEIVER_USERNAME AMOUNT TIMESTAMP

### Explanation:
The amount of AMOUNT currency is withdrawn from the account of the user with the name SENDER_USERNAME at the TIMESTAMP, and exactly one hour after that, it is deposited into the account of the user with the name RECEIVER_USERNAME.

### Output:
- If there is no user with the name SENDER_USERNAME or RECEIVER_USERNAME at the TIMESTAMP, print the message No Such User Found!
- If the amount of AMOUNT is more than 3000 currency units, print the message Maximum Amount Exceeded!
- If the balance of the account with the name SENDER_USERNAME was less than the amount of AMOUNT, print the message Not Enough Fund!
- Otherwise, print the balance of the account of the user with the name SENDER_USERNAME after transferring the amount.

## GET_BALANCE
### Input Format:
GET_BALANCE USERNAME TIMESTAMP

### Explanation:
At the TIMESTAMP, the balance of the account of the user with the name USERNAME is printed, and 10 currency units are deducted from that account.

### Output:
- If there is no user with the name USERNAME at the TIMESTAMP, print the message No Such User Found!
- If the balance of the account of the user with the name USERNAME was less than 10 currency units at the time of executing the operation, print the message Not Enough Fund!
- Otherwise, print the balance of the account of the user with the name USERNAME after deducting 10 currency units.

## ADD_BANKNOTE
### Input Format:
ADD_BANKNOTE VALUE AMOUNT TIMESTAMP

### Explanation:
At the TIMESTAMP, each of the AMOUNT banknotes with the VALUE value is added to the banknotes inside the ATM.

It is guaranteed that the VALUE is one of the values of 1, 5, 10, 50, or 100.

### Output:
After adding the banknotes, the total assets of the ATM (the sum of the banknotes inside it) should be printed.

## Notes:

- After registration, each user's initial account balance is 100 currency units.
- The DEPOSIT command does not add anything to the banknotes inside the ATM.
- In the WITHDRAW command, the ATM delivers the minimum number of banknotes if it pays the amount.
- Initially, the ATM has 10 banknotes of each of the denominations of 1, 5, 10, 50, and 100.
- It is guaranteed that the format of all TIMESTAMPS is YYYY/MM/DD-hh:mm:ss, where YYYY, MM, DD, hh, mm, and ss represent the year, month, day, hour, minute, and second of the operation, respectively. Also, all TIMESTAMPS have a valid value.
- All USERNAMES consist only of lowercase English letters and are at most 10 characters long.
- In each section, if more than one error occurs, consider the first error as the output.
- Commands are executed in order of TIMESTAMPS.

### Input:

The input contains at most 200 lines. The first line contains a number n, indicating the number of commands given. Then in the next n lines, each line contains one of the valid commands.

It is guaranteed that the format of the input commands is as specified, and also no two operations have the same TIMESTAMP. (Including deposits to the account in the TRANSFER operation)

### Output:

For each command given in the input, print the appropriate output on a separate line in order.
