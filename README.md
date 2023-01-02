# convbase
Shell command that convert an int from a base to another base (ascii characters).

Usage : convbase [NBR] [BASE_FROM] [BASE_TO]

NBR : can be preceded by any amount of spaces (isspace3), '+' and '-'.
The number of '-' determines the sign (odd == negative).

BASES : must contain at least 2 characters. Cannot contain twice the same char or spaces or '+' or '-'.

Compile it using make, and then place the exec in a binary folder (/usr/local/bin).
