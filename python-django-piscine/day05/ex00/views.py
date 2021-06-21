from django.shortcuts import render
from django.http import HttpResponse
import psycopg2

def init(request):
    
    table = """
        CREATE TABLE ex00_movies (
            title VARCHAR(64) NOT NULL,
            episode_nb SERIAL PRIMARY KEY,
            opening_crawl TEXT
            director VARCHAR(32) NOT NULL,
            producer VARCHAR(128) NOT NULL,
            release_date DATE
        )
    """

    return HttpResponse('<h1>It works!</h1>')
