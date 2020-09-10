obj = test.o
target = test-curl

all: $(obj)
	${CC} $(obj) -o $(target) $(LDFLAGS)

%.o:%.c
	${CC} $(CFLAGS) -c $^ -o $@ 

.PHONY: clean
clean:
	rm -rf $(obj) $(target)
