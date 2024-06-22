all:
	@echo "No need to build dragon-tiger in lab1. It is distributed as a binary executable."

submission:
	@git remote -v > VERSION
	@git rev-parse HEAD >> VERSION
	cd ../ && zip dragon-tiger.zip -r dragon-tiger -x \*dtiger -x \*.a
	@rm VERSION
	@echo "You can now submit ../dragon-tiger.zip"
