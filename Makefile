build:
	python3 main.py
	tectonic --keep-intermediates --keep-logs CheatSheet.tex
	rm -f content.tex *.log *.toc *.aux *.pyg
