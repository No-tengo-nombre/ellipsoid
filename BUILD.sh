cmake -S . -B ./build/
cmake --build ./build/

for arg in "$@"
do
    case $arg in
        -r|--run)
            ./build/app
    esac
done
