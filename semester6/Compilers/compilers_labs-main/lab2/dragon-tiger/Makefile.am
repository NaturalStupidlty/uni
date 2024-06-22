ACLOCAL_AMFLAGS = -I m4
SUBDIRS=src
EXTRA_DIST=./autogen.sh

submission:
	@git remote -v > VERSION
	@git rev-parse HEAD >> VERSION
	@make dist-zip
	@mv dragon-tiger-submission.zip ../dragon-tiger.zip
	@zip -z ../dragon-tiger.zip < VERSION > /dev/null
	@rm VERSION
