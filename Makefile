8b1t:	8b1t.cpp

clean:
	rm 8b1t

stairway:  8b1t
	cat stairway.txt | ./8b1t | aplay -r 9250 &
	cat chord1.txt | ./8b1t | aplay -r 9250 &
	cat chord2.txt | ./8b1t | aplay -r 9250 &
	cat bass.txt | ./8b1t | aplay -r 9250 &
