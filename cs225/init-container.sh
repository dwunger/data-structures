docker build -t cs225 .
cd ..
docker run --rm -it \
    -v "$(pwd)":/workspace \
    -v "$HOME/.git-credentials":/root/.git-credentials \
    -v "$HOME/.gitconfig":/root/.gitconfig \
    -w /workspace/cs225 \
    cs225

