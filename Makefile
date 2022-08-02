all:
	docker build -t wyga/app-volume-template build/
	docker push wyga/app-volume-template:latest
