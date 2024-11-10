setup() {
    load 'bats/bats-support/load'
    load 'bats/bats-assert/load'
}

# Normal usage
# ------------

@test "./factorial 0" {
    run ./factorial 0
    assert_output 1
    assert_success
}

@test "./factorial 1" {
    run ./factorial 1
    assert_output 1
    assert_success
}

@test "./factorial 2" {
    run ./factorial 2
    assert_output 2
    assert_success
}

@test "./factorial 3" {
    run ./factorial 3
    assert_output 6
    assert_success
}

@test "./factorial 19" {
    run ./factorial 19
    assert_output 121645100408832000
    assert_success
}

@test "./factorial 20" {
    run ./factorial 20
    assert_output 2432902008176640000
    assert_success
}

# Errors
# ------

@test "./factorial with no argument" {
    run ./factorial
    assert_output 'error: Exactly one argument must be provided'
    assert_failure 1
}

@test "./factorial a" {
    run ./factorial a
    assert_output 'error: The argument must be an integer between 0 and 20'
    assert_failure 1
}

@test "./factorial -1" {
    run ./factorial -1
    assert_output 'error: The argument must be an integer between 0 and 20'
    assert_failure 1
}

@test "./factorial 21" {
    run ./factorial 21
    assert_output 'error: The argument must be an integer between 0 and 20'
    assert_failure 1
}
