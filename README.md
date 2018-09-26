
The International Pi Day happens every year on March 14. 
This problem is inspired by an article I read this year titled [Pi Day: 12 fun facts and ways to celebrate](https://enterprisersproject.com/article/2018/3/pi-day-12-fun-facts-and-ways-celebrate?utm_medium=Email&utm_campaign=&sc_cid=701f2000000tyL0AAI) by  Carla Rudder.
There is a claim in the article that the 22 trillion known digits of pi take nearly 9 terabytes when stored in a file.
Well, this means that we should be able to store 22\*10^12 digits in 9\*10^12 bytes (assuming we are using powers of 10 instead of powers of 2 to calculate a terabyte). 
This means that we are able to store 2.4 digits in a single byte. If we store each digit as individual character in a text file, than we are using 1 byte for each 
digit/character. 

Your task for this problem is to write a program that reads in a text file containing digits of pi (each digit is a single 1 byte character) and create a new file
that contains the same digits but saved in a more efficient/compact way.

In order to verify that your code actually saves the digits (instead of throwing half of them away), your program should provide _conversion_ in both ways (from the
text representation to the compact representation and from the compact representation to the text representation). For that purpose the program should take three command line arguments:

- a single letter `c` or `e` to indicate if the program should _compress_,`c`, the text 
into more compact representation, or _extract_, `e`, the text from the more compact representation. 
- name of the input file
- name of the output file 

In particular, when the program is run as follows:

```
./problem2 c pi_1000 pi_1000_short
./problem2 e pi_1000_short pi_1000_extracted
```

then the two files: `pi_1000` and `pi_1000_extracted`  should be identical. 

You can assume that any valid input file will contain only digits. The last character in the file might be a newline character. 
