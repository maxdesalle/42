from django.shortcuts import render, redirect
from django.core.paginator import Paginator
from django.conf import settings
from django.contrib import messages
from forum.models import Post, Upvote, Downvote
import random


def forum(request):
    posts = Post.objects.all().order_by('-date')
    paginator = Paginator(posts, 3) 

    page_number = request.GET.get('page')
    page_obj = paginator.get_page(page_number)
    return render(request, 'forum/forum.html', {'page_obj': page_obj})



def downup(request, id):

    post = Post.objects.get(id=id)

    try:
        downvote = Downvote.objects.create(user=request.user, post=post)
        if downvote.vote == True:
            downvote.vote = False
            downvote.save()
            post.downstats -= 1
            post.downusers.remove(request.user)
            post.save()

    except:
        downvote = Downvote.objects.get(user=request.user, post=post)
        if downvote.vote == True:
            downvote.vote = False
            downvote.save()
            post.downstats -= 1
            post.downusers.remove(request.user)
            post.save()


def upvote(request, id):

    post = Post.objects.get(id=id)

    try:
        upvote = Upvote.objects.create(user=request.user, post=post)
        post.upstats += 1
        post.upusers.add(request.user)
        post.save()
        upvote.vote = True
        upvote.save()
        downup(request, id)

    except:
        upvote = Upvote.objects.get(post=post, user=request.user)
        if upvote.vote == True:
            post.upstats -= 1
            post.upusers.remove(request.user)
            post.save()
            upvote.vote = False
            upvote.save()
        else:
            post.upstats += 1
            post.upusers.add(request.user)
            post.save()
            upvote.vote = True
            upvote.save()
            downup(request, id)

    return redirect('/forum')


def updown(request, id):

    post = Post.objects.get(id=id)

    try:
        upvote = Upvote.objects.create(user=request.user, post=post)
        if upvote.vote == True:
            upvote.vote = False
            upvote.save()
            post.upstats -= 1
            post.upusers.remove(request.user)
            post.save()

    except:
        upvote = Upvote.objects.get(user=request.user, post=post)
        if upvote.vote == True:
            upvote.vote = False
            upvote.save()
            post.upstats -= 1
            post.upusers.remove(request.user)
            post.save()


def downvote(request, id):

    post = Post.objects.get(id=id)

    try:
        downvote = Downvote.objects.create(user=request.user, post=post)
        post.downstats += 1
        post.downusers.add(request.user)
        post.save()
        downvote.vote = True
        downvote.save()
        updown(request, id)

    except:
        downvote = Downvote.objects.get(user=request.user, post=post)
        if downvote.vote == True:
            post.downstats -= 1
            post.downusers.remove(request.user)
            post.save()
            downvote.vote = False
            downvote.save()
        else:
            post.downstats += 1
            post.downusers.add(request.user)
            post.save()
            downvote.vote = True
            downvote.save()
            updown(request, id)

    return redirect('/forum')


def delete(request, id):
   
    post = Post.objects.get(id=id)
    Upvote.objects.filter(post=post).delete()
    Downvote.objects.filter(post=post).delete()
    Post.objects.filter(id=id).delete()

    return redirect('/forum')
