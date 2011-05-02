8b1t:	8b1t.cpp

clean:
	rm 8b1t

stairway:  8b1t
	cat stairway.txt | ./8b1t | aplay
