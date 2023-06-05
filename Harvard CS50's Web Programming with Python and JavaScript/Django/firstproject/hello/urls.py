from django.urls import path
from . import views

urlpatterns = [
    path("", views.index, name="index"),
    path("<str:name>", views.greet, name="greet"),
    path("joseph", views.joseph, name="joseph"),
    path("david", views.david, name="david")
]