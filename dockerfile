# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/07 14:54:59 by jcollon           #+#    #+#              #
#    Updated: 2021/11/07 16:54:59 by jcollon          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

FROM debian:10

RUN apt update && apt install -y make build-essential

WORKDIR /app

COPY . /app

RUN make

RUN adduser player && chown -R player /app

USER player

CMD ./bot