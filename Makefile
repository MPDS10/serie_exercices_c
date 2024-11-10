bats = bats/bats-core/bin/bats

# Build
# -----

factorial: factorial.c
	gcc -o $@ $<

mystery: mystery.c
	gcc -o $@ $<

hw: hw.c
	gcc -o $@ $<

motzkin: motzkin.c
	gcc -o $@ $<

# Test
# ----

test: test-factorial test-mystery test-hw

test-factorial: factorial factorial.bats
	$(bats) factorial.bats

test-mystery: mystery mystery.bats
	$(bats) mystery.bats

test-hw: hw hw.bats
	$(bats) hw.bats
