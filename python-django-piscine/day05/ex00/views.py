from django.shortcuts import render
from django.http import HttpResponse
import psycopg2

def init(request):
   
    table = """
        CREATE TABLE IF NOT EXISTS ex00_movies (
        	title VARCHAR(64) UNIQUE NOT NULL,
			episode_nb INTEGER PRIMARY KEY,
			opening_crawl TEXT,
			director VARCHAR(32) NOT NULL,
			producer VARCHAR(128) NOT NULL,
			release_date DATE NOT NULL
            )
            """

    DB_HOST = "localhost"
    DB_NAME = "djangotraining"
    DB_USER = "djangouser"
    DB_PASS = "secret"

    try:
        conn = psycopg2.connect(database=DB_NAME, user=DB_USER, password=DB_PASS, host=DB_HOST)
        curr = conn.cursor()
        curr.execute(table)
        conn.commit()
        conn.close()
        curr.close()

        return HttpResponse('OK')

    except Exception as e:
        return HttpResponse('Error: {}'.format(e))
