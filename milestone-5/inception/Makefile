.PHONY : all re clean fclean up down

all:
	mkdir -p /home/amarquez/data/mariadb
	mkdir -p /home/amarquez/data/wordpress
	docker compose -f ./srcs/docker-compose.yml -p inception up -d --build

down:
	docker compose -f ./srcs/docker-compose.yml -p inception down

up:
	docker compose -f ./srcs/docker-compose.yml -p inception up -d --build

downup: down up

clean: down
	sudo rm -rf ~/data/*

fclean: clean
	-docker stop $$(docker ps -qa)
	-docker rm $$(docker ps -qa)
	-docker rmi -f $$(docker images -qa)
	-docker volume rm $$(docker volume ls -q)
	-docker network rm $$(docker network ls -q)
	-docker system prune -a

re: fclean
	mkdir -p /home/amarquez/data/mariadb
	mkdir -p /home/amarquez/data/wordpress
	docker compose -f ./srcs/docker-compose.yml -p inception up -d --build