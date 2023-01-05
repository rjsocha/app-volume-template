all:
	docker buildx build --platform "linux/amd64,linux/arm64" -t "wyga/deploy-template:v1" --push --pull --no-cache -f build/Dockerfile build
